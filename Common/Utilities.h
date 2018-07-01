<<<<<<< HEAD
=======
<<<<<<< HEAD
#pragma once

=======
>>>>>>> 42f1bc5536035529e963704b3d4046fb4a3a12ff
>>>>>>> master
#include <iostream>
#include <string>
#include <time.h>

namespace Util
{
	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	const std::string CurrentDateTime()
	{
		time_t     now = time(NULL);
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		return buf;
	}
}
