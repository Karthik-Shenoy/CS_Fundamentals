// package: todoPackage
// file: todo.proto

/* tslint:disable */
/* eslint-disable */

import * as grpc from "@grpc/grpc-js";
import * as todo_pb from "./todo_pb";

interface ITodoService extends grpc.ServiceDefinition<grpc.UntypedServiceImplementation> {
    createTodo: ITodoService_IcreateTodo;
    readTodo: ITodoService_IreadTodo;
    readTodos: ITodoService_IreadTodos;
}

interface ITodoService_IcreateTodo extends grpc.MethodDefinition<todo_pb.TodoItem, todo_pb.TodoItem> {
    path: "/todoPackage.Todo/createTodo";
    requestStream: false;
    responseStream: false;
    requestSerialize: grpc.serialize<todo_pb.TodoItem>;
    requestDeserialize: grpc.deserialize<todo_pb.TodoItem>;
    responseSerialize: grpc.serialize<todo_pb.TodoItem>;
    responseDeserialize: grpc.deserialize<todo_pb.TodoItem>;
}
interface ITodoService_IreadTodo extends grpc.MethodDefinition<todo_pb.voidMessage, todo_pb.TodoItem> {
    path: "/todoPackage.Todo/readTodo";
    requestStream: false;
    responseStream: false;
    requestSerialize: grpc.serialize<todo_pb.voidMessage>;
    requestDeserialize: grpc.deserialize<todo_pb.voidMessage>;
    responseSerialize: grpc.serialize<todo_pb.TodoItem>;
    responseDeserialize: grpc.deserialize<todo_pb.TodoItem>;
}
interface ITodoService_IreadTodos extends grpc.MethodDefinition<todo_pb.voidMessage, todo_pb.TodoItem> {
    path: "/todoPackage.Todo/readTodos";
    requestStream: false;
    responseStream: true;
    requestSerialize: grpc.serialize<todo_pb.voidMessage>;
    requestDeserialize: grpc.deserialize<todo_pb.voidMessage>;
    responseSerialize: grpc.serialize<todo_pb.TodoItem>;
    responseDeserialize: grpc.deserialize<todo_pb.TodoItem>;
}

export const TodoService: ITodoService;

export interface ITodoServer extends grpc.UntypedServiceImplementation {
    createTodo: grpc.handleUnaryCall<todo_pb.TodoItem, todo_pb.TodoItem>;
    readTodo: grpc.handleUnaryCall<todo_pb.voidMessage, todo_pb.TodoItem>;
    readTodos: grpc.handleServerStreamingCall<todo_pb.voidMessage, todo_pb.TodoItem>;
}

export interface ITodoClient {
    createTodo(request: todo_pb.TodoItem, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    createTodo(request: todo_pb.TodoItem, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    createTodo(request: todo_pb.TodoItem, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    readTodo(request: todo_pb.voidMessage, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    readTodo(request: todo_pb.voidMessage, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    readTodo(request: todo_pb.voidMessage, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    readTodos(request: todo_pb.voidMessage, options?: Partial<grpc.CallOptions>): grpc.ClientReadableStream<todo_pb.TodoItem>;
    readTodos(request: todo_pb.voidMessage, metadata?: grpc.Metadata, options?: Partial<grpc.CallOptions>): grpc.ClientReadableStream<todo_pb.TodoItem>;
}

export class TodoClient extends grpc.Client implements ITodoClient {
    constructor(address: string, credentials: grpc.ChannelCredentials, options?: Partial<grpc.ClientOptions>);
    public createTodo(request: todo_pb.TodoItem, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public createTodo(request: todo_pb.TodoItem, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public createTodo(request: todo_pb.TodoItem, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public readTodo(request: todo_pb.voidMessage, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public readTodo(request: todo_pb.voidMessage, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public readTodo(request: todo_pb.voidMessage, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: todo_pb.TodoItem) => void): grpc.ClientUnaryCall;
    public readTodos(request: todo_pb.voidMessage, options?: Partial<grpc.CallOptions>): grpc.ClientReadableStream<todo_pb.TodoItem>;
    public readTodos(request: todo_pb.voidMessage, metadata?: grpc.Metadata, options?: Partial<grpc.CallOptions>): grpc.ClientReadableStream<todo_pb.TodoItem>;
}
