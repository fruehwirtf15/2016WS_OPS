
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o ".\Funktion.o" ".\Funktion.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o ".\InterfaceOptVerfahren.o" ".\InterfaceOptVerfahren.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o ".\NotLinOpt.o" ".\NotLinOpt.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o ".\GS.o" ".\GS.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o ".\FB.o" ".\FB.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "BI.o" ".\BI.cpp" 
g++ -o NotLinOpt.exe "BI.o" "FB.o" "Funktion.o" "GS.o" "InterfaceOptVerfahren.o" ".\NotLinOpt.o" 



