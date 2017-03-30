//ImageManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _ImageManager
#define _ImageManager


#include <string>
#include <map>
#include "Image.h"
#include "TextureManager.h"
#include "Texture.h"

class ImageManager
{
private:

	Image *imagePtr;

	static ImageManager* instance;

	//constructors all in one place
	ImageManager();
	~ImageManager();
	ImageManager(const ImageManager&){};
	ImageManager operator=(const ImageManager&){};


	static ImageManager& getInstance()
	{
		//if instance is null
		//make new instance with constructor
		if (instance == nullptr)
		{
			instance = new ImageManager();
		}

		return *instance;
	}
	friend class Viridian;

	std::string DefaultPath = "Textures/";

	typedef std::string ImageKey;
	typedef std::map <ImageKey, Image*> ImageMap;

	ImageMap imageMap;


	//Private Methods
	void PrivLoadSpriteImage(const ImageKey& imageKey, Texture* texture, Rect* rect);
	Image* PrivGetSpriteImage(const ImageKey& imageKey);

	static void DeleteImages();

public:

	//Public Methods
	static void LoadSpriteImage(const ImageKey& imageKey, std::string textureKey);
	static Image* GetSpriteImage(const ImageKey& imageKey);


};
#endif _ImageManager