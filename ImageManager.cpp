//ImageManager.cpp
//Jacqueline Passehl Winter Quarter 2k16


#include "ImageManager.h"
#include "Image.h"
#include "AzulCore.h"

ImageManager* ImageManager::instance = nullptr;

ImageManager::ImageManager()
{

}
void ImageManager::PrivLoadSpriteImage(const ImageKey& imageKey, Texture* texture, Rect* rect)
{
	
	auto search = imageMap.find(imageKey);
	
	if(search !=imageMap.end())
	{
		DebugMsg::out("The image %s has already been loaded \n", imageKey.c_str());
	}
	else
	{
		imageMap[imageKey] = new Image(texture, rect);
		DebugMsg::out("Image %s loaded\n", imageKey.c_str());
	}
}
Image* ImageManager::PrivGetSpriteImage(const ImageKey& imageKey)
{
	return imageMap[imageKey];
}
void ImageManager::LoadSpriteImage(const ImageKey& imageKey, std::string textureKey)
{
	Texture* texture = TextureManager::GetTexture(textureKey);
	Rect* rect = new Rect(0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height));
	getInstance().PrivLoadSpriteImage(imageKey, texture, rect);

}
Image* ImageManager::GetSpriteImage(const ImageKey& imageKey)
{
	return getInstance().PrivGetSpriteImage(imageKey);
}
ImageManager::~ImageManager()
{
	DebugMsg::out("\nImage Manager Destructor Called\n");

	for (auto it = instance->imageMap.begin(); it != instance->imageMap.end(); ++it)
	{
		DebugMsg::out("\nDeleting Image %s", it->first.c_str());
		delete it->second;
	}

	instance->imageMap.clear();
}
void ImageManager::DeleteImages()
{
	DebugMsg::out("\nImage Manager Delete Called");

	delete instance;
	instance = nullptr;
}

