#pragma once
#include "Acommand.h"

class AddCommand : public ACommand
{
public:
	AddCommand(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::ADD);
		return pReciever_->GetResult();
	}
};

class SubtractCommand : public ACommand
{
public:
	SubtractCommand(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::SUBTRACT);
		return pReciever_->GetResult();
	}
};

class MultiplyCommand : public ACommand
{
public:
	MultiplyCommand(IReciever *reciever)
		: ACommand(reciever)
	{

	}

	int Execute()
	{
		pReciever_->SetAction(TYPES::ACTION_LIST::MULTIPLY);
		return pReciever_->GetResult();
	}
};
