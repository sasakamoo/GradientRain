all: Rain.exe

Rain.exe: olcPixelGameEngine.cpp utils.cpp GradientRain.cpp Rain.cpp app.cpp
	g++ -o app.exe olcPixelGameEngine.cpp utils.cpp GradientRain.cpp Rain.cpp app.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

clean:
	rm app.exe