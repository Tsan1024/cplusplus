#include <iostream>
#include <boost/asio.hpp>

class AsynchronousOperation {
public:
    AsynchronousOperation(boost::asio::io_context& ioContext)
        : ioContext(ioContext), timer(ioContext) {}

    // Initiate asynchronous operation
    void startAsyncOperation() {
        timer.expires_after(std::chrono::seconds(1));
        timer.async_wait([this](const boost::system::error_code& ec) {
            if (!ec) {
                handleOperationCompletion();
            }
        });
    }

    // Handle completion of asynchronous operation
    void handleOperationCompletion() {
        std::cout << "Asynchronous operation completed!" << std::endl;
    }

private:
    boost::asio::io_context& ioContext;
    boost::asio::steady_timer timer;
};

int main() {
    boost::asio::io_context ioContext;

    // Client initiates asynchronous operation
    AsynchronousOperation asyncOperation(ioContext);
    asyncOperation.startAsyncOperation();

    // Continue doing other work without waiting for the operation to complete
    ioContext.run();

    return 0;
}
