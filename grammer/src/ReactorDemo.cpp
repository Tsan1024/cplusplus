#include <iostream>
#include <boost/version.hpp>
#include <thread>

class EventHandler {
public:
    virtual void handleEvent() = 0;
    virtual ~EventHandler() {}
};

class Reactor {
public:
    void registerHandler(int eventType, EventHandler* handler) {
        eventHandlers[eventType] = handler;
    }

    void removeHandler(int eventType) {
        eventHandlers.erase(eventType);
    }

    void handleEvents() {
        while (true) {
            // 模拟事件的发生，这里可以根据实际需要修改
            int eventType = rand() % 3;

            // 查找对应事件类型的处理器
            auto it = eventHandlers.find(eventType);
            if (it != eventHandlers.end()) {
                // 调用事件处理器的处理方法
                it->second->handleEvent();
            } else {
                std::cout << "No handler registered for event type " << eventType << std::endl;
            }

            // 休眠一段时间，模拟事件的间隔
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

private:
    std::unordered_map<int, EventHandler*> eventHandlers;
};

class ConcreteEventHandler : public EventHandler {
public:
    ConcreteEventHandler(const std::string& name) : name(name) {}

    void handleEvent() override {
        std::cout << "Handling event in " << name << std::endl;
    }

private:
    std::string name;
};

int main() {
    Reactor reactor;

    // 注册事件处理器
    ConcreteEventHandler handler1("Handler1");
    ConcreteEventHandler handler2("Handler2");

    reactor.registerHandler(0, &handler1);
    reactor.registerHandler(1, &handler2);

    // 启动事件处理循环
    reactor.handleEvents();

    return 0;
}
