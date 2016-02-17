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

#include "myotest-prerecorded-data-collection/datacollection.h"
#include <math.h>

void datacollection_convertRawTicks2Ms(sample_t* sample, uint32_t tickHz){
    uint64_t ticks = sample->timestamp;
    ticks = round(ticks/((float) tickHz / 1000));
    sample->timestamp = ticks;
}

void datacollection_convertRawAcc2Mg(sample_t* sample, uint8_t gRange, uint8_t adcBits){
	//not yet implemented
	(void) sample;
	(void) gRange;
	(void) adcBits;
}

void datacollection_convertTiTag2Mg(sample_t *sample)
	{
	sample->x = round((float)sample->x * 1000.0f / 32.0f);
	sample->y = round((float)sample->y * 1000.0f / 32.0f);
	sample->z = round((float)sample->z * 1000.0f / 32.0f);
}
