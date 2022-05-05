cd build
cmake ..
cmake --build .

cp src/libEngine.so ../../EngineTestGame/
sudo rm -rf /usr/include/MonkeEngine
sudo cp -r ../src /usr/include/
sudo mv /usr/include/src /usr/include/MonkeEngine
sudo ls /usr/include/MonkeEngine

cd ../../EngineTestGame

sh .buildme.sh
