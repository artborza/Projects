<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html lang="th">
<head>
    <meta http-equiv="Content-Language" content="th">
    <meta http-equiv="content-Type" content="text/html; charset=window-874">
    <meta http-equiv="content-Type" content="text/html; charset=tis-620">
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js"></script>

    <title>Waste-En</title>

    <style>
    body {font-family: Arial, Helvetica, sans-serif;}

    /* The Modal (background) */
    .modal {
        display: none; /* Hidden by default */
        position: fixed; /* Stay in place */
        z-index: 1; /* Sit on top */
        padding-top: 100px; /* Location of the box */
        left: 0;
        top: 0;
        width: 100%; /* Full width */
        height: 100%; /* Full height */
        overflow: auto; /* Enable scroll if needed */
        background-color: rgb(0,0,0); /* Fallback color */
        background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
    }

    /* Modal Content */
    .modal-content {
        position: relative;
        background-color: #fefefe;
        margin: auto;
        padding: 0;
        border: 1px solid #888;
        width: 40%;
        box-shadow: 0 4px 8px 0 rgba(0,0,0,0.2),0 6px 20px 0 rgba(0,0,0,0.19);
        -webkit-animation-name: animatetop;
        -webkit-animation-duration: 0.4s;
        animation-name: animatetop;
        animation-duration: 0.4s
    }

    /* Add Animation */
    @-webkit-keyframes animatetop {
        from {top:-300px; opacity:0}
        to {top:0; opacity:1}
    }

    @keyframes animatetop {
        from {top:-300px; opacity:0}
        to {top:0; opacity:1}
    }

    /* The Close Button */
    .close {
        color: white;
        float: right;
        font-size: 28px;
        font-weight: bold;
    }

    .close:hover,
    .close:focus {
        color: #000;
        text-decoration: none;
        cursor: pointer;
    }

    .modal-header {
        padding: 2px 16px;
        background-color: #5cb85c;
        color: white;
    }

    .modal-body {padding: 2px 16px;}

    .modal-footer {
        padding: 2px 16px;
        background-color: #5cb85c;
        color: white;
    }
</style>

    <style>
        * {box-sizing: border-box;}

        /* Style the body */
        body {
            font-family: Arial, Helvetica, sans-serif;
            margin: 0;
        }

        .header {
            padding: 1px;
            text-align: left;
            background: #2a9d8f;
            color: white;
        }

        /* Increase the font size of the heading */
        .header h1 {
            font-size: 20px;
        }
    </style>

    <style>
        * {box-sizing: border-box}
        body {font-family: "Lato", sans-serif;}

        /* Style the tab */
        .tab {
            float: left;
            border: 0px solid #ccc;
            background-color: #264653;
            width: 10%;
            height: 750px;
        }

        /* Style the buttons inside the tab */
        .tab button {
            display: block;
            background-color: inherit;
            color: white;
            padding: 22px 16px;
            width: 100%;
            border: none;
            outline: none;
            text-align: left;
            cursor: pointer;
            transition: 0.3s;
            font-size: 17px;
        }

        /* Change background color of buttons on hover */
        .tab button:hover {
            background-color: #264653;
        }

        /* Create an active/current "tab button" class */
        .tab button.active {
            background-color: #1d2e34;
        }

        /* Style the tab content */
        .tabcontent {
            float: left;
            padding: 0px 8px;
            border: 0px solid #ccc;
            width: 90%;
            border-left: none;
            height: auto;
            background-color: #d5ddd4;

        }
        .column {
            float: left;
            width: 80%;
            margin-bottom: 20px;
            padding: 0px 5px;


        }
        .column2 {
            float: left;
            width: 20%;
            margin-bottom: 20px;
            padding: 0 5px;


        }
        .column3 {
            float: left;
            width: 45%;
            margin-bottom: 20px;
            padding: 0 5px;
        }
        .column4 {
            float: left;
            width: 55%;
            margin-bottom: 20px;
            padding: 0 5px;
        }

        .card {
            box-shadow: 0 4px 4px 0 rgba(0, 0, 0, 0.2);
            margin: 4px;
            padding: 12px 6px;
            height: 700px;
        }
        .card2 {
            box-shadow: 0 4px 4px 0 rgba(0, 0, 0, 0.2);
            margin: 4px;
            padding: 12px 6px;
            height: 80px;

        }

        .card3 {
            box-shadow: 0 4px 4px 0 rgba(0, 0, 0, 0.2);
            border: 0px solid #ccc;
            background-color: #302727;
            margin: 4px;
            padding: 10px 5px;
            color: #248b18;
            height: 60px;
        }


    </style>
    <!--Picture-->
    <style>
        .gallery {
            margin: 5px;
            border: 1px solid #ccc;
            float: left;
            width: 100px;
            display: none;
        }

        .show {
            display: block;
        }

        .container {
            margin-top: 20px;
            overflow: hidden;
        }
        .gallery:hover {
            border: 1px solid #777;
        }


        .gallery img {
            width: 100%;
            height: auto;
        }

        .desc {
            padding: 1px;
            text-align: center;
        }
    </style>
    <!--Type of Botton-->
    <style>
        .btn {
            border: 2px solid black;
            background-color: white;
            color: black;
            padding: 7px 14px;
            font-size: 16px;
            cursor: pointer;
        }

        .btn2 {
            background-color: white;
            color: black;
            padding: 14px 40px;
            font-size: 20px;

        }

        .success {
            border-color: #4CAF50;
            color: green;

        }

        .success:hover {
            background-color: #4CAF50;
            color: white;
        }
        .success.active {
            background-color: #4CAF50;
            color: white;
        }
        .steel {
            border-color: #97b5c3;
            color: dodgerblue;
        }
        .steel:hover {
            background: #97b5c3;
            color: white;
        }
        .steel.active {
            background: #97b5c3;
            color: white;
        }
        .paper {
            border-color: #c3b77f;
            color: #c3b77f;
        }
        .paper:hover {
            background: #c3b77f;
            color: white;
        }
        .paper.active {
            background: #c3b77f;
            color: white;
        }
        .glass {
            border-color: #096261;
            color: #096261;
        }
        .glass:hover {
             background: #096261;
             color: white;
         }
        .glass.active {
            background: #096261;
            color: white;
        }
        .plastic {
            border-color: #127364;
            color: #127364;
        }
        .plastic:hover {
            background: #127364;
            color: white;
        }
        .plastic.active {
            background: #127364;
            color: white;
        }
        .metals {
            border-color: #c2ac19;
            color: #c2ac19;
        }
        .metals:hover {
            background: #c2ac19;
            color: white;
        }
        .metals.active {
            background: #c2ac19;
            color: white;
        }
        .waste {
            border-color: #fae047;
            color: #fae047;
        }
        .waste:hover {
            background: #fae047;
            color: white;
        }
        .waste.active {
            background: #fae047;
            color: white;
        }
        .others {
            border-color: #4e3b40;
            color: #4e3b40;
        }
        .others:hover {
            background: #4e3b40;
            color: white;
        }
        .others.active {
            background: #4e3b40;
            color: white;
        }


    </style>
    <!--Modal-->

</head>
<body>

<div class="header">
    <h1><b> &nbsp Waste-En</b></h1>
</div>
<div class="tab">
    <button class="tablinks" onclick="openCity(event, 'ListMenu')" id="defaultOpen">List Menu</button>

</div>


<div id="ListMenu" class="tabcontent">
    <div class="column">
    <div class="card">
        <div id="myBtnContainer">
        <button class="btn success active" onclick="filterSelection('all')">All</button>
        <button class="btn steel" onclick="filterSelection('steel')">Steel</button>
        <button class="btn paper" onclick="filterSelection('paper')">Paper</button>
        <button class="btn glass" onclick="filterSelection('glass')">Glass</button>
        <button class="btn plastic" onclick="filterSelection('plastic')">Plastic</button>
        <button class="btn metals" onclick="filterSelection('Nonferrous metal')">Nonferrous metals</button>
        <button class="btn waste" onclick="filterSelection('E-waste')">E-waste</button>
        <button class="btn others" onclick="filterSelection('other')"> Other scraps</button>
        </div>

        <div class="container">
        <c:forEach items="${productsList}" var="product">
        <div class="gallery ${product.type}">
            <button id="myBtn" >
                <img src=${product.picture} alt="Cinque Terre" width="600" height="400">
            </button>
            <div class="desc">${product.name}</div>
            <div class="desc">${product.price} Bath</div>
        </div>
            <!-- The Modal -->
            <div id="myModal" class="modal">

                <!-- Modal content -->
                <div class="modal-content">
                    <div class="modal-header">
                        <h2>Buy</h2>
                        <span class="close">&times;</span>
                    </div>
                    <div class="modal-body">
                        <div class="column3">
                            <p></p>
                        <img src=${product.picture} alt="Cinque Terre" width="200" height="200">
                        </div>
                        <div class="column4">
                            <p></p><br>
                            <p>Product : ${product.name} </p>
                            <p>Price : ${product.price} Bath/Kg.</p>
                            <p>Type : ${product.type}</p>
                            <form  action="/products/sale" method="post">
                                <input type="hidden" name="price"
                                       value="${product.price}">
                                <input type="hidden" name="name"
                                       value="${product.name}">
                                <p> Amount: <input class="w3-input" type="text" name="number"><br></p>
                                <button class="btn success">Submit</button>
                            </form>
                        </div>
                    </div>
                </div>

            </div>

        </c:forEach>
    </div>
    </div><br>

    </div>
    <div class="column2">
        <div class="card">
            <div class="card3" align="right">
                <h2>00028.6</h2>
            </div>
            <p><br></p>
            <c:forEach items="${salesList}" var="sale">
            <div class="card2"> <b>
                <p>${sale.number} Kg. | ${sale.name}</p>
                <p>Total price : ${sale.total}</p> </b>
            </div>
            <script>
            </script>
            </c:forEach>
        </div>
    </div>
</div>

<script>
    // Get the modal
    var modal = document.getElementById("myModal");

    // Get the button that opens the modal
    var btn = document.getElementById("myBtn");

    // Get the <span> element that closes the modal
    var span = document.getElementsByClassName("close")[0];

    // When the user clicks the button, open the modal
    btn.onclick = function() {
        modal.style.display = "block";
    }

    // When the user clicks on <span> (x), close the modal
    span.onclick = function() {
        modal.style.display = "none";
    }

    // When the user clicks anywhere outside of the modal, close it
    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }
</script>

<script>
    filterSelection("all")
    function filterSelection(c) {
        var x, i;
        x = document.getElementsByClassName("gallery");
        if (c == "all") c = "";
        for (i = 0; i < x.length; i++) {
            w3RemoveClass(x[i], "show");
            if (x[i].className.indexOf(c) > -1) w3AddClass(x[i], "show");
        }
    }

    function w3AddClass(element, name) {
        var i, arr1, arr2;
        arr1 = element.className.split(" ");
        arr2 = name.split(" ");
        for (i = 0; i < arr2.length; i++) {
            if (arr1.indexOf(arr2[i]) == -1) {element.className += " " + arr2[i];}
        }
    }

    function w3RemoveClass(element, name) {
        var i, arr1, arr2;
        arr1 = element.className.split(" ");
        arr2 = name.split(" ");
        for (i = 0; i < arr2.length; i++) {
            while (arr1.indexOf(arr2[i]) > -1) {
                arr1.splice(arr1.indexOf(arr2[i]), 1);
            }
        }
        element.className = arr1.join(" ");
    }

    // Add active class to the current button (highlight it)
    var btnContainer = document.getElementById("myBtnContainer");
    var btns = btnContainer.getElementsByClassName("btn");
    for (var i = 0; i < btns.length; i++) {
        btns[i].addEventListener("click", function(){
            var current = document.getElementsByClassName("active");
            current[0].className = current[0].className.replace(" active", "");
            this.className += " active";
        });
    }
</script>

<script>
    function openCity(evt, cityName) {
        var i, tabcontent, tablinks;
        tabcontent = document.getElementsByClassName("tabcontent");
        for (i = 0; i < tabcontent.length; i++) {
            tabcontent[i].style.display = "none";
        }
        tablinks = document.getElementsByClassName("tablinks");
        for (i = 0; i < tablinks.length; i++) {
            tablinks[i].className = tablinks[i].className.replace(" active", "");
        }
        document.getElementById(cityName).style.display = "block";
        evt.currentTarget.className += " active";
    }

    // Get the element with id="defaultOpen" and click on it
    document.getElementById("defaultOpen").click();
</script>

</body>
</html>