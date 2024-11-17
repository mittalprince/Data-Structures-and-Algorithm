package com.example.repository;

import com.example.entity.Product;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class InMemoryProductRepository implements ProductRepository{
    private Map<String, Product> products;

    public InMemoryProductRepository(){
        products = new ConcurrentHashMap<>();
    }

    public void addProduct(Product product){
        products.put(product.getId(), product);
    }
    public void removeProduct(String productId){
        products.remove(productId);
    }
    public Product getProductById(String productId){
        return products.get(productId);
    }
    public List<Product> getAllProducts() {
        return new ArrayList<>(products.values());
    }
}
