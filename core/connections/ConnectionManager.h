/*
* File: ConnectionManager.h
* Author: trung.la
* Date: 02-05-2025
* Description: ConnectionManager class
*/

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

class ViewModelController;
class ModelController;

class ConnectionManager
{
public:
    ConnectionManager();
    ~ConnectionManager();

    void connectViewModelAndModel(ViewModelController *viewModelController, ModelController *modelController);
};

#endif // CONNECTIONMANAGER_H