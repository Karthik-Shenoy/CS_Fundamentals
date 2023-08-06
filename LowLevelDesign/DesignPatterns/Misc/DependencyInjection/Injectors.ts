import { Consumer, Consumer1 } from "./Consumers";
import { Service1, Service2 } from "./Services";

export interface ServiceInjector{
    getConsumer(): Consumer;
}

export class Service1Injector implements ServiceInjector{
    public getConsumer(): Consumer {
        return new Consumer1(new Service1());
    }
}

export class Service2Injector implements ServiceInjector{
    public getConsumer(): Consumer {
        return new Consumer1(new Service2());
    }
}