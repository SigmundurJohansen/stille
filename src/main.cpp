#include <vulkan/vulkan.h>
#include <iostream>
#include <../external/Avarice/include/service_locator.h>
#include <../external/Avarice/core/game.h>
#include <../external/Avarice/entrypoint.h>

using namespace Avarice;

class SuperGame : public Game
{
public:
    InputManager *m_inputManager;

    void SetGameSettings()
    {
        m_inputManager = ServiceLocator::GetInputManager();
        if(m_inputManager)
        {
            std::cout << "setting input manager \n";
            m_inputManager->MapInputToAction(InputKey::KEY_A, InputAction{ .actionName = "strafe" });
            m_inputManager->MapInputToAction(InputKey::MOUSE_LEFT, InputAction{ .actionName = "click" });

            m_inputManager->RegisterActionCallback("strafe", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "pressing buttons";
                return true;
            }
            });
            m_inputManager->RegisterActionCallback("click", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [this] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "clicking";
                return true;
            }
            });
        }
    }

    explicit SuperGame(std::string _title) : Game(std::move(_title))
    {
        SetGameSettings();
        
        std::cout << "Hello" << std::endl;
    }

protected:
    virtual void Update(float _deltaTime) override
    {
        std::cout << "i'm updating" << std::endl;
    }
};

Game *Avarice::CreateGame()
{
    return new SuperGame("main game");
}