.PHONY:all
all:syscall syscall2

syscall:syscall.go
	go build syscall.go
syscall2:syscall2.go
	go build syscall2.go

.PHONY:clean
clean:
	rm -f syscall syscall2
