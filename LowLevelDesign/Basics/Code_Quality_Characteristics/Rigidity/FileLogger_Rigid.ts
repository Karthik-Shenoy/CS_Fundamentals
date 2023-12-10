class Product{
    private _name = "";
    constructor(name: string){
        if(name != "")
            this._name = name;
    }
    public get name(){
        return this._name;
    }
}

class ProductStore{
    private _productList: Product[] =[];
    private _logger = new FileLogger();
    public addProduct(product: Product){
        this._productList.push(product);
        this._logger.addTrace(`ProductStore: added product (${product.name}) to the prodcut store`);
    }
    public removeProduct(purchasedProduct: Product){
        let productIndex = 0;
        for(let idx = 0; idx < this._productList.length; idx++){
            if(this._productList[idx] === purchasedProduct)
            {
                productIndex = idx;
                break;
            }
        }
        // delete operation on array
        for(let idx = productIndex; idx < this._productList.length-1; idx++){
            this._productList[idx] = this._productList[idx+1];
        }
        this._productList.pop();
        this._logger.addTrace(`ProductStore: removed product (${purchasedProduct.name}) to the prodcut store`);
    }
    public isProductPresent(prodcut: Product){
        return this._productList.indexOf(prodcut) !== -1;
    }
}

class User{
    private _userId = 0;
    private _logger = new FileLogger();
    constructor(){
        this._userId = Date.now() % 100000;
        this._logger.addTrace(`User (${this._userId}) created`);
    }
    public purchaseProduct(product: Product, productStore: ProductStore){
        if(productStore.isProductPresent(product)){
            this._logger.addTrace(`User (${this._userId}) purchased the product (${product.name})`);
            productStore.removeProduct(product);
        }
        else{
            this._logger.addTrace(`The requeseted Product has already been purchased.`);
        }
    }
}

class FileLogger{
    public addTrace(traceString: string){
        console.log("added the following log to the file : ", traceString)
    }
}

const user1 = new User();
const user2 = new User();
const product1 = new Product("milk");
const product2 = new Product("Bread");
const product3 = new Product("milk"); // same prduct but diff ID
const productStore = new ProductStore();

console.log("\n");

productStore.addProduct(product1);
productStore.addProduct(product2);
productStore.addProduct(product3);

console.log("\n");

user1.purchaseProduct(product1, productStore);
user1.purchaseProduct(product1, productStore); // cant purchase as the product is already gone
user1.purchaseProduct(product2, productStore);