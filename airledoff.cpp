#include <iostream>
#include <windows.h>

#include "ec.hpp"

int main()
{
    EmbeddedController ec = EmbeddedController();

    // Making sure driver file loaded successfully
    if (ec.driverFileExist && ec.driverLoaded)
    {
    	Sleep(3000);
		ec.writeByte(0x6d, 0x03);
		ec.writeByte(0xb1, 0x02);
		ec.writeByte(0xbf, 0x10);
		Sleep(5); // AYASpace does this so copied it here
		ec.writeByte(0xbf, 0xfe);
        // Free up the resources at the end
        ec.close();
    }

}