all: app build\app.o build\GradientRain.o build\utils.o build\olcPixelGameEngine.o

build\olcPixelGameEngine.o: src\olcPixelGameEngine.cpp
	g++ src\olcPixelGameEngine.cpp -o build\olcPixelGameEngine.o -c -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

build\utils.o: src\utils.cpp
	g++ src\utils.cpp -o build\utils.o -c -std=c++17

build\GradientRain.o: src\GradientRain.cpp
	g++ src\GradientRain.cpp -o build\GradientRain.o -c -std=c++17

build\app.o: src\app.cpp
	g++ src\app.cpp -o build\app.o -c -std=c++17

app: build\app.o build\GradientRain.o build\utils.o build\olcPixelGameEngine.o
	g++ -o app.exe build\app.o build\GradientRain.o build\utils.o build\olcPixelGameEngine.o -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -std=c++17

clean:
	rm app.exe build\app.o build\GradientRain.o build\utils.o build\olcPixelGameEngine.o