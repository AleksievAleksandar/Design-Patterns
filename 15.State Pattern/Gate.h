#ifndef GATE_H
#define GATE_H

#include <iostream>

struct IGateState
{
	virtual void enter() = 0;
	virtual void payOK() = 0;
	virtual void payFailed() = 0;

	~IGateState() = default;
};

struct IGate
{
	IGateState* gateState;
	virtual void changeState(IGateState* state) = 0;
	~IGate() = default;
};

class OpenGateState : public IGateState
{
	IGate* gate;
public:
	OpenGateState(IGate* gate) :
		gate(gate) {}
public:
	void payOK() override
	{
		this->gate->changeState(this);
	}
	void payFailed() override;
	void enter() override;
};

class ClosedGateState : public IGateState
{
	IGate* gate;
public:
	ClosedGateState(IGate* gate) :
		gate(gate) {}
public:
	void payOK() override
	{
		this->gate->changeState(new OpenGateState(gate));
	}
	void payFailed() override
	{
		this->gate->changeState(this);
	}
	void enter() override
	{
		std::cout << "Pay first\n";
	}
};

void OpenGateState::payFailed()
{
	this->gate->changeState(new ClosedGateState(gate));
}
void OpenGateState::enter()
{
	this->gate->changeState(new ClosedGateState(gate));
}

class Gate : public IGate
{
public:
	Gate()
	{
		this->gateState = new ClosedGateState(this);
	}
	~Gate()
	{
		delete this->gateState;
	}
public:
	virtual void changeState(IGateState* state) override
	{
		if (this->gateState != state)
		{
			delete this->gateState;
			this->gateState = state;
		}
	}
	void payOK()
	{
		this->gateState->payOK();
	}
	void payFailed()
	{
		this->gateState->payFailed();
	}
	void enter()
	{
		this->gateState->enter();
	}
};

#endif // !GATE_H
