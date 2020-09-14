/* Header for the Manager class (Manager.h) */
#ifndef MANAGER_H
#define MANAGER_H
#include "Session.cpp"
#include "Detail.h"
class Manager{
	private:
		Session session
		
	public:
		void login(Details user);
		void register(Details user);
		void requestReset(Detail user);
		void RestePassword(Detail user);
};


#endif
