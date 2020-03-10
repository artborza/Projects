<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit</title>
    <style>
        .header {
            padding: 50px;
            text-align: center;
            background: #75b0cc;
            color: white;
        }
        .btn {
            border: none;
            color: white;
            padding: 14px 28px;
            font-size: 16px;
            cursor: pointer;
        }

        .success {background-color: #4CAF50;} /* Green */
        .success:hover {background-color: #46a049;}
        </style>
        </head>
<body>
<div class="header">
    <h2 align = 'center'>  Edit price and amount of ${product.name} </h2>
</div><br>
<form align = 'center' action="/products/edit" method="post" >
    <input type="hidden" name="id"
           value="${product.id}">
    Price : <input type="text" name="price" value="${product.price}"><br><br>
    Number: <input type="text" name="number" value="${product.number}" ><br><br>
    <button class="btn success">Edit</button>
</form>
</body>
</html>