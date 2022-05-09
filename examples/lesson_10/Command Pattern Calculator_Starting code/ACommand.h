#pragma once

class ACommand
{
protected:

	IReciever *pReciever_;

public:

	ACommand(IReciever *reciever)
		:pReciever_(reciever)
	{
	}

	virtual int Execute() = 0;
};
