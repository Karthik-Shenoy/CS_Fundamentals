import * as grpc from "@grpc/grpc-js";
import * as protoLoader from "@grpc/proto-loader"

const packageDef = protoLoader.loadSync("./todo.proto", {});
const todoPackage = grpc.loadPackageDefinition(packageDef).todoPackage as grpc.GrpcObject;
const todoServiceObject = todoPackage.Todo as grpc.GrpcObject;
const todoService = todoServiceObject.service;

const server = new grpc.Server();
server.bind("0.0.0.0:5000", grpc.ServerCredentials.createInsecure());
server.addService(todoServiceObject.service as grpc.GrpcProtoBufDefination);




