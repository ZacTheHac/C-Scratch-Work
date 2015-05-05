#pragma once
class nodeClass
{
public:
	nodeClass();
	~nodeClass();
private://well fuck... now we need to make functions to handle everything
	int info;
	nodeClass *nextLink;
	nodeClass *prevLink;
};

