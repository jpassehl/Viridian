//Model Manager.cpp
//Jacqueline Passehl Winter Quarter 2k16

#include <string>
#include <map>
#include "ModelManager.h"
#include "Model.h"
#include "AzulCore.h"

ModelManager* ModelManager::instance = nullptr;

ModelManager::ModelManager()
{

}
void ModelManager :: PrivLoadModel(const ModelKey& key, const std::string& path)
{
	//temp string
	std::string tempFilename = DefaultPath + path;

	//convert the string to a const char pointer
	const char* filenameChar = tempFilename.c_str();


	auto search = modelMap.find(filenameChar);
	if (search != modelMap.end())
	{
		DebugMsg::out("Model has already been loaded\n", key.c_str());
	}
	else
	{
		//create a new model object
		Model *newModelObject = new Model(filenameChar);

		//map the model to the key
		modelMap[key] = newModelObject;

		//print out the the console that the model was loaded
		DebugMsg::out("Model Loaded %s\n", key.c_str());
	}

}
void ModelManager::LoadModel(const ModelKey& key, const std::string& path)
{
	getInstance().PrivLoadModel(key, path);
}
Model* ModelManager::PrivGetModel(const ModelKey& key)
{
	return modelMap[key];
}
Model* ModelManager::GetModel(const ModelKey& key)
{
	return getInstance().PrivGetModel(key);
}
void ModelManager:: DeleteModels()
{
	DebugMsg::out("\nModel Manager Delete Called\n");

	for (std::map<std::string, Model*>::iterator it = instance->modelMap.begin(); it != instance->modelMap.end(); ++it)
	{
		DebugMsg::out("\nDeleting Model %s", it->first.c_str());
		delete it->second;
	}

	instance->modelMap.clear();

}

