#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct sample_t{
    uint64_t timestamp;
    int32_t x;
    int32_t y;
    int32_t z;
} sample_t;

typedef struct rawdata_t{
    const sample_t* data;
    uint32_t length;
    uint32_t tickHz;
    uint8_t gRange;
    uint8_t adcBits;
} rawdata_t;


//not yet implemented
void datacollection_convertRawTicks2Ms(sample_t* sample, uint32_t tickHz);
void datacollection_convertRawAcc2Mg(sample_t* sample, uint8_t gRange, uint8_t adcBits);

//modifies the content of sample.
//how to use: 
//1. get a copy of a sample from a data-set array
//2. pass the address of this copied sample to this function
//3. pass the modified sample to the myoAPI_acquisition function
void datacollection_convertTiTag2Mg(sample_t* sample);

#ifdef  __cplusplus
}
#endif

#endif /* DATACOLLECTION_H */
