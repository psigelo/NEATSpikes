#ifndef NEAT_BASICSYNAPTICWEIGHT_HPP
#define NEAT_BASICSYNAPTICWEIGHT_HPP


#include "SynapticWeight.hpp"
#include "BasicSynapticWeightUserDefinitions.hpp"
#include "Parameter.hpp"

namespace NEAT
{
class BasicSynapticWeight : public SynapticWeight
{
public:
	BasicSynapticWeight();
	BasicSynapticWeight( const BasicSynapticWeightUserDefinitions& userdef );
	BasicSynapticWeight( const BasicSynapticWeight& other );
	virtual ~BasicSynapticWeight();
	void mightMutate() override;
	void spread() override;
	float getDistance( const SynapticWeight * sw ) const override;
	std::unique_ptr < SynapticWeight > clone() const override;
	std::unique_ptr < SynapticWeight > createNew() const override;
	void printInfo() const;

private:

	std::unique_ptr < Parameter > weight;
	float constantDistanceOfSynapticWeightValue;
	float mutationProbability;

};
}
#endif