"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Consumers_1 = require("./Consumers");
var Injectors_1 = require("./Injectors");
var Services_1 = require("./Services");
function test() {
    // testing service 1
    var testInjector = new Injectors_1.Service1Injector();
    var testConsumer = testInjector.getConsumer();
    testConsumer.useService("| service1 test usage |");
    // testing service 2
    testInjector = new Injectors_1.Service2Injector();
    testConsumer = testInjector.getConsumer();
    testConsumer.useService("| servcew2 test usage |");
    // when coding we can create a service and consune it like this
    var service = new Services_1.Service1();
    var consumer = new Consumers_1.Consumer1(service);
    consumer.useService("| service1 actual usage |");
}
test();
