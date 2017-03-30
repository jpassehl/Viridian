//ModelManager.h
//Jacqueline Passehl Winter Quarter 2k16

#ifndef _ModelManager
#define _ModelManager


#include <string>
#include <map>
#include "Model.h"
#include "AzulCore.h"

class ModelManager
{
private:
	static ModelManager* instance;

	//constructors all in one place
	ModelManager();
	~ModelManager()
	{ 
		DebugMsg::out("Model Manager Destructor Called"); 
	};
	ModelManager(const ModelManager&){};
	ModelManager operator=(const ModelManager&){};


	static ModelManager& getInstance()
	{
		//if instance is null
		//make new instance with constructor
		if (instance == nullptr)
		{
			instance = new ModelManager();
		}

		return *instance;
	}
	friend class Viridian;

	//std::string defaultFilename;
	std::string DefaultPath = "Models/";

	typedef std::string ModelKey;
	typedef std::map <ModelKey, Model*> ModelMap;

	ModelMap modelMap;


	//Private Methods
	void PrivLoadModel(const ModelKey& key, const std::string& path);
	Model* PrivGetModel(const ModelKey& key);

	static void DeleteModels();

public:

	//Public Methods
	static void LoadModel(const ModelKey& key, const std::string& path);
	static Model* GetModel(const ModelKey& key);


};
#endif _ModelManager