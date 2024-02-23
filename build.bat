
SET buildDir=build

IF NOT EXIST %buildDir% MKDIR %buildDir%

cd %buildDir%

cmake ..
cmake --build . 
cd ./Debug
start "" "./FireReborn.exe"