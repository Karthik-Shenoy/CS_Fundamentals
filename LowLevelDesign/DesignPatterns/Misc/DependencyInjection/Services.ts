export interface Service{
    serviceOperation(data: string): void;
}

export class Service1 implements Service{
    serviceOperation(data: string): void {
        console.log(`Service1 : processing the given data : ${data}`);
    }
}

export class Service2 implements Service{
    serviceOperation(data: string): void {
        console.log(`Service2 : processing the given data : ${data}`);
    }
}


