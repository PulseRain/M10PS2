/*
###############################################################################
# Copyright (c) 2018, PulseRain Technology LLC 
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License (LGPL) as 
# published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
# or FITNESS FOR A PARTICULAR PURPOSE.  
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################
*/

#include "M10PS2.h"

//----------------------------------------------------------------------------
// ps2_init()
//
// Parameters:
//      None
//     
// Return Value:
//      None
//
// Remarks:
//      call this function to init the PS2 module
//----------------------------------------------------------------------------

static void ps2_init() __reentrant
{
    PS2_CSR = 0;
    PS2_DATA = 0;
    
} // End of ps2_init()


//----------------------------------------------------------------------------
// ps2_data_available()
//
// Parameters:
//      None
//     
// Return Value:
//      1 when there is data in the FIFO
//      0 when FIFO is empty
//
// Remarks:
//      call this function to see if there is data in the receiving FIFO
//----------------------------------------------------------------------------

static uint8_t ps2_data_available() __reentrant
{    
    if (PS2_CSR) {
        return 1;
    } else {
        return 0;
    }
} // End of ps2_data_available() 

//----------------------------------------------------------------------------
// ps2_read()
//
// Parameters:
//      None
//     
// Return Value:
//      the scan code from the PS2 keyboard
//
// Remarks:
//      call this function to read data from the receiving FIFO
//----------------------------------------------------------------------------

static uint8_t ps2_read() __reentrant
{
    uint8_t t;
    
    t = PS2_DATA;
    PS2_CSR = 0;
    
    return t;

} // End of ps2_read()


const PS2_STRUCT PS2 = {
    .init = ps2_init,
    .dataAvailable = ps2_data_available,
    .read = ps2_read
};
