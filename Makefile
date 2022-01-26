all: app app.o GradientRain.o utils.o olcPixelGameEngine.o

olcPixelGameEngine.o: olcPixelGameEngine.cpp
	g++ olcPixelGameEngine.cpp -o olcPixelGameEngine.o -c -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

utils.o: utils.cpp
	g++ utils.cpp -o utils.o -c -std=c++17

GradientRain.o: GradientRain.cpp
	g++ GradientRain.cpp -o GradientRain.o -c -std=c++17

app.o: app.cpp
	g++ app.cpp -o app.o -c -std=c++17

app: app.o GradientRain.o utils.o olcPixelGameEngine.o
	g++ -o app.exe app.o GradientRain.o utils.o olcPixelGameEngine.o -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -std=c++17

clean:
	rm app.exe app.o GradientRain.o utils.o olcPixelGameEngine.o