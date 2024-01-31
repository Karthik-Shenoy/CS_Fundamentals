import * as grpc from "@grpc/grpc-js";
import * as protoLoader from "@grpc/proto-loader"

type TodoItem = {
    id: number;
    text: string;
}


// const packageDef = protoLoader.loadSync("./protoBufs/todo.proto", {});
// const todoPackage = grpc.loadPackageDefinition(packageDef).todoPackage as grpc.GrpcObject;
// const todoServiceObject = todoPackage.Todo as grpc.GrpcObject;
// const todoService: any = todoServiceObject.service as grpc;

// const todoItems: TodoItem[] = []


// const server = new grpc.Server();
// server.bind("0.0.0.0:5000", grpc.ServerCredentials.createInsecure());
// server.addService(todoService.createTodo , (todoItem: TodoItem)=>{
//     todoItems.push(todoItem)
// });




