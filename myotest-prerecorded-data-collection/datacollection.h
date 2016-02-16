/* **************************************************************************
*
*
     __  __             _            _      _____             
    |  \/  |           | |          | |    / ____|    /\      
    | \  / |_   _  ___ | |_ ___  ___| |_  | (___     /  \     
    | |\/| | | | |/ _ \| __/ _ \/ __| __|  \___ \   / /\ \    
    | |  | | |_| | (_) | ||  __/\__ \ |_   ____) | / ____ \ _ 
    |_|  |_|\__, |\___/ \__\___||___/\__| |_____(_)_/    \_(_)
             __/ |                                            
            |___/                                             
*
* Copyright (c) 2004-2016 Myotest SA
*
* PackageLicenseDeclared: Apache-2.0 
* 
* Licensed under the Apache License, Version 2.0 (the "License"); 
* you may not use this file except in compliance with the License. 
* You may obtain a copy of the License at 
* 
*     http://www.apache.org/licenses/LICENSE-2.0 
* 
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
* See the License for the specific language governing permissions and 
* limitations under the License. 
****************************************************************************/

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
