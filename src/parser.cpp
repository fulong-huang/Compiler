#include <iostream>
#include "Parser.h"
Parser::Parser(FileReader* f){
	fd = f;
};

Parser::~Parser(){
	
};

void Parser::run(){
	std::cout << "RUNNING: " << std::endl;
	int lhs = number();
	int op = relOp();
	int rhs = number();
	if(op <= -3 || op >= 3){
		std::cout << "UNKOWN OPERATION" << std::endl;
		abort();
	};
	switch(op){
		case -2:
			std::cout << (lhs < rhs) << std::endl;
			break;
		case -1:
			std::cout << (lhs <= rhs) << std::endl;
			break;
		case 0:
			std::cout << (lhs == rhs) << std::endl;
			break;
		case 1:
			std::cout << (lhs >= rhs) << std::endl;
			break;
		case 2:
			std::cout << (lhs > rhs) << std::endl;
			break;
		default: 
			std::cout << "UNKOWN" << std::endl;
	};
	std::cout << "FINISHED RUNNING" << std::endl;
};

int Parser::relOp(){
	switch(fd->get()){
		case '=':
			fd->eat();
			if(fd->get() != '='){
				throw std::invalid_argument("relOp received UNKONWN TOKEN");
			};
			fd->eat();
			fd->removeSpaces();
			return 0;
			break;
		case '!':
			fd->eat();
			if(fd->get() != '='){
				throw std::invalid_argument("relOp received UNKONWN TOKEN");
			};
			fd->eat();
			fd->removeSpaces();
			return 3;
			break;
		case '<':
			fd->eat();
			if(fd->get() != '='){
				fd->removeSpaces();
				return -2;
			};
			fd->eat();
			fd->removeSpaces();
			return -1;
			break;
		case '>':
			fd->eat();
			if(fd->get() != '='){
				fd->removeSpaces();
				return 2;
			};
			fd->eat();
			fd->removeSpaces();
			return 1;
			break;
		default:
			throw std::invalid_argument("relOp received UNKONWN TOKEN");
	};
	return -3;
};

void Parser::ident(){
	
};

int Parser::number(){
	int result = fd->getNum();
	fd->removeSpaces();
	return result;
};



