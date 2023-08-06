import { Consumer, Consumer1 } from "./Consumers";
import { Service1Injector, Service2Injector, ServiceInjector } from "./Injectors";
import { Service, Service1 } from "./Services";

function test(){
    // testing service 1
    let testInjector: ServiceInjector = new Service1Injector(); 
    let testConsumer: Consumer = testInjector.getConsumer();
    testConsumer.useService("| service1 test usage |");

    // testing service 2
    testInjector = new Service2Injector();
    testConsumer = testInjector.getConsumer();
    testConsumer.useService("| servcew2 test usage |");

    // when coding we can create a service and consune it like this
    let service: Service = new Service1();
    let consumer: Consumer = new Consumer1(service);
    consumer.useService("| service1 actual usage |")
}

test();