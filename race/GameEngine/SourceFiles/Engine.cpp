#include "Engine.h"
#include "ErrorHandler.h"

#include "MessagingSystem.h"

void Engine::start() {
    // Create the other engines, or at least get pointer to them
	_fileEngine_p = new FileEngine();
	if (_fileEngine_p == nullptr) {
		std::cout << ErrorHandler::getErrorString(1) << std::endl;
	}
    _renderEngine_p = new RenderEngine();
    if (_renderEngine_p == nullptr) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }
    _physicsEngine_p = new PhysicsEngine();
    if (_physicsEngine_p == nullptr) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }
    _aiEngine_p = new AIEngine();
    if (_aiEngine_p == nullptr) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }
    _inputEngine_p = new InputEngine();
    if (_inputEngine_p == nullptr) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }
    _soundEngine_p = new SoundEngine();
    if (_soundEngine_p == nullptr) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }
    try {
		_fileEngine_p->start();
        _renderEngine_p->start();
        //_physicsThread_p = _physicsEngine_p->start();
        //_aiThread_p = _aiEngine_p->start();
        _inputEngine_p->start();
        _soundEngine_p->start();
    } catch (std::exception e) {
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
    }

	_running = true;
    _engineThread_p = new std::thread(&Engine::loop, this);

	
	
	/*
    if (!_running) {
        _running = true;
    } else {
        this->stop();
        std::cout << ErrorHandler::getErrorString(1) << std::endl;
        delete this;
    }

	*/
	
}

void Engine::update() {
    //SDL_Log("%s", "Running Engine::udpate"); //NO NO NO NO NO NO NO!
}

void Engine::loop() {
	bool ran = false;

    if (!_running) {
        return;
    }
    while(_running) {
		//SDL_Log("This one should work");

        this->update();
		//std::this_thread::sleep_for(std::chrono::milliseconds(17));

		if (ran)
			continue;

		SDL_Log("Doing a stupid befpre!");

		//std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		SDL_Log("Doing a stupid!");

		//disgusting render test hack
		
		MessagingSystem *ms = &MessagingSystem::instance();		
		{			
			RenderLoadMessageContent *rlmc = new RenderLoadMessageContent();
			RenderableSetupData rsd;
			rsd.models.push_back("cube");
			rlmc->data = rsd;
			Message *msg = new Message(RenderLoadMessageType,false,rlmc);
			ms->postMessage(std::shared_ptr<Message>(msg));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		{
			RenderDrawMessageContent *rdmc = new RenderDrawMessageContent();
			RenderableScene *rs = new RenderableScene();
			rdmc->scene_p = rs;

			RenderableCamera rc;
			rc.clearColor = glm::vec3(1, 1, 1);
			rc.farPlane = 1000.0f;
			rc.nearPlane = 0.1f;
			rc.position = glm::vec3(0, 0, 5);
			rc.rotation = glm::vec3(0, 0, 0); //x=pitch, y=yaw, z=roll
			rc.viewAngle = 1.05f;
			rs->camera = rc;

			RenderableObject cube1;
			cube1.albedoName = "crate";
			cube1.normalName = "";
			cube1.smoothness = 0.5;
			cube1.modelName = "cube";
			cube1.position = glm::vec3(0, 2, 2);
			cube1.rotation = glm::vec3(0, 0, 0);
			cube1.scale = glm::vec3(1, 1, 1);
			rs->objects.push_back(cube1);

			RenderableObject cube2;
			cube2.albedoName = "crate";
			cube2.normalName = "";
			cube2.smoothness = 1;
			cube2.modelName = "cube";
			cube2.position = glm::vec3(1, 1, -1.5);
			cube2.rotation = glm::vec3(0.5, 0.5, 0.5);
			cube2.scale = glm::vec3(1.25, 1.25, 1.25);
			rs->objects.push_back(cube2);

			RenderableObject sphere;
			sphere.modelName = "sphere";
			sphere.albedoName = "rainbow";
			sphere.normalName = "rainbow_n";
			sphere.smoothness = 0;
			sphere.position = glm::vec3(-1.5, -0.5, 0);
			sphere.rotation = glm::vec3(0,0,0);
			sphere.scale = glm::vec3(1, 1, 1);
			rs->objects.push_back(sphere);

			RenderableLight mainLight;
			mainLight.type = RenderableLightType::AMBIENT;
			mainLight.intensity = 0.5;
			mainLight.color = glm::vec3(1, 1, 1);
			rs->lights.push_back(mainLight);

			Message *msg = new Message(RenderDrawMessageType, false, rdmc);
			ms->postMessage(std::shared_ptr<Message>(msg));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

		ran = true;

    }
}

///
/// <title>
/// Engine Stop
/// </title>
/// <summary>
/// Will stop the engine from running. This will halt the main loop and other 
/// threads. The main purpose is to halt the game here. This can be a 
/// catch-all for other cleanup that is required in a stop/start of the game.
/// </summary>
/// 
void Engine::stop() {
    _running = false;
    _physicsEngine_p->stop();
    _aiEngine_p->stop();
}

Engine::Engine() {

}

Engine::~Engine() {
    _soundEngine_p->~SoundEngine();
    _inputEngine_p->~InputEngine();
    _aiEngine_p->~AIEngine();
    _physicsEngine_p->~PhysicsEngine();
    _renderEngine_p->~RenderEngine();
	_fileEngine_p->~FileEngine();
}