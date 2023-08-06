import { Service, Service1, Service2 } from "./Services";

export interface Consumer {
    service: Service;
    useService(data: string): void;
}

export class Consumer1 implements Consumer {
    service: Service;
    public constructor(service: Service){
        this.service = service;
    }
    useService(data): void {
        this.service.serviceOperation(data);
    }
}
