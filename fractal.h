#ifndef FRACTAL_H
#define FRACTAL_H

#include <string>
#include <memory>
#include <vector>
#include "zoomlist.h"
#include "pixel.h"
#include "colorscheme.h"
#include "bitmap.h"
#include "histogram.h"

class Fractal {

	protected:
		uint _width; // szerokość obrazu
		uint _height; // wysokość obrazu
		ZoomList _zoomList; // lista zoomów
		std::vector<Pixel> _fractal; // vector pixeli
		std::unique_ptr<ColorScheme> _coloringMethod { nullptr }; // Metoda kolorowania pixeli
		Bitmap _outputFile; // Plik wynikowy. TODO: Dodać możliwość innych typów ( jpg, png, whatever )
		Fractal ( );
	public:
		void setDimensions ( int width, int height );
		std::string _fractalName {};
		void addZoom ( Zoom zoom );
		// Oblicza dane dla fractala w zależności od jego rodzaju i ustawia te dane w pikselach
		virtual void calculateFractal () = 0;
		/* Koloruje piksele fraktala na podstawie danych policzonych wczesniej i schematu kolorowania
		 * Póki co ino histogram
		 */
		void colorFractal ();
		// Zapisuje fractal do pliku
		void save ();
		virtual ~Fractal () {}
};

#endif // FRACTAL_H
