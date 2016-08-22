#ifndef NEAT_SPIECIES_HPP
#define NEAT_SPIECIES_HPP

#include <memory>
#include <random>
#include <map>
#include <string>
#include "Race.hpp"
#include "SpiciesUserDefinitions.hpp"


namespace NEAT
{

class Spicies
{

public:
	Spicies( std::unique_ptr <Race> founderRace );
	Spicies( const SpiciesUserDefinitions& userdef, std::unique_ptr <Race> founderRace  );
	void epoch( const uint childrenAmount );
	std::unique_ptr <Organism> getOrganismNewSpiciesCandidate();
	bool isExtincted();
	float getMeanFitnessOfOldRaces();

private:
	void fillFitnessVector (std::vector <float> & fitnessVector);
	bool detectRepeatedInnovation( const Organism & orgm );
	Race& getRandomRace_ref();
	void createRacesFromOrganismCandidates();
	void createDecendence(const uint amountOfChildrens ); 
	void deleteExtinctedRaces();

	std::vector< std::unique_ptr<Race> > oldRaces;
	std::vector< std::unique_ptr<Race> > youngRaces;
	uint maxAmountOfRacesPerSpicie;
	std::unique_ptr < std::default_random_engine > generator;
	std::map <std::string , bool> innovMsgMap; // Is true if this innov exists   

};


}

#endif