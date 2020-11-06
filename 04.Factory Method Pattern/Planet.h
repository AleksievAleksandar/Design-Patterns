#ifndef PLANET_H
#define PLANET_H

enum class PlanetType
{
	ROCKY   = 1,
	GAS	    = 2,
	ICE     = 3,

	UNKNOWN = 255
};

class Planet
{
protected:
	double mass;
	PlanetType planetType;

public:
	Planet():
	mass(0), planetType(PlanetType::UNKNOWN){}

	Planet(double mass, PlanetType planetType) :
		mass(mass), planetType(planetType) {}
};

class Earth : public Planet
{
public:
	Earth(double mass) :
		Planet(mass, PlanetType::ROCKY) {}
};

class Jupiter : public Planet
{
public:
	Jupiter(double mass) :
		Planet(mass, PlanetType::GAS) {}
};

class Uranus : public Planet
{
public:
	Uranus(double mass) :
		Planet(mass, PlanetType::ICE) {}
};

#endif // !PLANET_H
