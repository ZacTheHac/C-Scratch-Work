#pragma once
#include "LinkList.h"
template <class Type> class MyStack//because using a prebuilt is EVIL
{
public:
	MyStack(){}
	~MyStack(){}
	void push(Type input){
		InternalLinkList.addRecord(input, 1);
	}//I don't really understand the difference between this and emplace. emplace just seems to allow live construction, but the language already does that...
	//it seems to have VERY slightly different underlying code, but I'm just not going to have an emplace function

	bool pop(){
		return InternalLinkList.deleteRecord(1);
		//already returns false if you can't.
		//this returning is not part of the original stack specs, but this is MyStack, no relation to stack... none at all.
		//I definitely didn't have a function in here that let you convert stacks to MyStacks originally.
	}
	int size(){
		return InternalLinkList.getLength();
	}
	Type top(){
		return InternalLinkList.getRecord(1);
		//was going to do a null return if it's not valid, but I forgot I already did that in LinkList
	}
	bool empty(){
		return (InternalLinkList.getLength() == 0);
	}
//I was going to impliment the swap functions, but they were proving a bit tricky, and I have no use for them.
private:
	LinkList<Type> InternalLinkList;
	//I was going to hardcode this as a boolean, because I don't want to be marked down for more style errors by making it a template, thereby having all inline code. 
	//even though my LinkList class already does that...
	//nvm: if I'm gonna get marked down for it anyways, might as well make it semi-useful outside of this lab.
};

