#include <poll.h>
#include <sys/types.h>

typedef struct CorooThread CorooThread;
typedef void (*CorooThreadFunction)(void *);

void coroo_thread_init();
CorooThread *coroo_thread_start(size_t stack_size,
		CorooThreadFunction thread_function,
		void *thread_argument);
void coroo_thread_yield();
void coroo_thread_exit();

short coroo_poll_simple(int fd, short events, int64_t timeout);
void coroo_poll(struct pollfd *fds, nfds_t nfds, int64_t timeout);

typedef struct CorooBufIO CorooBufIO;

CorooBufIO *coroo_bufio_create(size_t buffer_size, struct pollfd *poll_desc);
short coroo_bufio_update(CorooBufIO *bio);
void coroo_bufio_tunnel(CorooBufIO *dst, CorooBufIO *src);
