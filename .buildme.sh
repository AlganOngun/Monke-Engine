cd build
cmake ..
cmake --build .

cp src/libEngine.so ../../EngineTestGame/

cd ../../EngineTestGame

sh .buildme.sh
