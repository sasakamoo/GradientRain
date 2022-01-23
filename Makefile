all: PurpleRain.exe

PurpleRain.exe: olcPixelGameEngine.cpp utils.cpp PurpleRain.cpp
	g++ -o app.exe olcPixelGameEngine.cpp utils.cpp PurpleRain.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

clean:
	rm app.exe