#include "Channel.h"
#include "SceneManager.h"
#include "SoundManager.h"

Channel::Channel()
{
	//make a new channel
	soundChannel = SoundChannel();
}
void Channel::privSetChannelPos(Vect& vect)
{
	SceneManager::GetSoundManager()->setChannel(soundChannel, vect);
	//SceneManager::GetSoundManager()->SetChannelMinMax(soundChannel);
}
void Channel::SetChannelPosition(Vect& vect)
{
	privSetChannelPos(vect);
};
