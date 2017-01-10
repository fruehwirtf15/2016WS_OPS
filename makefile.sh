
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//Funktion.o" ".//src//Funktion.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//InterfaceOptVerfahren.o" ".//src//InterfaceOptVerfahren.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//NotLinOpt.o" ".//src//NotLinOpt.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//GS.o" ".//src//GS.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//FB.o" ".//src//FB.cpp" 
g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -DETYPE=std::string -DDEBUG -Wextra -pedantic -o "src//BI.o" ".//src//BI.cpp" 
g++ -o NotLinOpt.exe "src//BI.o" "src//FB.o" "src//Funktion.o" "src//GS.o" "src//InterfaceOptVerfahren.o" "src//NotLinOpt.o" 



