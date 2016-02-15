#include "myotest-data-collection/datacollection.h"
#include <math.h>

void datacollection_convertRawTicks2Ms(sample_t* sample, uint32_t tickHz){
    uint64_t ticks = sample->timestamp;
    ticks = round(ticks/((float) tickHz / 1000));
    sample->timestamp = ticks;
}

void datacollection_convertRawAcc2Mg(sample_t* sample, uint8_t gRange, uint8_t adcBits){
	//not yet implemented
}

void datacollection_convertTiTag2Mg(sample_t *sample)
	{
	sample->x = round((float)sample->x * 1000.0f / 32.0f);
	sample->y = round((float)sample->y * 1000.0f / 32.0f);
	sample->z = round((float)sample->z * 1000.0f / 32.0f);
}
