/**
 *  @file       Device.h (header only)
 *  @version    1.0.1
 *  @author     utuM (Kostyantyn Komarov)
 *  @date       7.12.2018 (release)
 *  @brief      Basic external devices or sensors class description.
 *              This class represents device or a sensor using fields
 *              that give all basic information you need. 
 **/

#ifndef __DRIVER_DEVICE_H
#define __DRIVER_DEVICE_H

#include <string>

#include "Interface.h"

namespace Driver {
    /**
     *	Template device class.
     **/
    template <typename T>
    class Device {
        private:
            char m_name[16];      ///< Device name.
		
        public:
            T m_interface;        ///< Device's communication interface.

            // Class constructors and destructor.
            Device(void) { /* Leave empty. */ }
			
            /**
             * Device class constructor.
             * @param[i] std::string name - name of current device.
             **/
            Device(std::string name)
            {
                name = (name.length() >= 16 ? name.substr(0, 15) : name);
                sprintf(m_name, "%s", name.c_str());
            }
            ~Device(void) { /* Leave empty. */ }
			
            // Class getter.
            std::string getName(void) { return std::string(m_name); }
    };
}

#endif // __DRIVER_DEVICE_H
