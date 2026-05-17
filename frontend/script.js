// alert("JS working");
// console.log("aditya");
// console.dir(document.body.childNodes);
// document.body.childNodes[1].innerText="abcd";
// let heading=document.getElementById("one");
// console.log(heading);
// let cl=document.getElementsByClassName("heading");
// console.log(cl);
// let vari=document.querySelectorAll("p");
// console.log(vari[0].tagName);
// console.log(document.body.innerText);
// // console.log(div.innerText)
// let boxes=document.querySelectorAll(".box");
// boxes[0].innerText=boxes[0].innerText+"one";
// boxes[1].innerText=boxes[1].innerText+"two";
// boxes[2].innerText=boxes[2].innerText+"three";
// console.log(boxes[0]);
// console.log(boxes[1]);
// console.log(boxes[2]);
// console.log(document.body.style.backgroundColor);
// document.body.div.style.backgroundColor="green";
// let button=document.createElement("button");
// button.innerText="button";
// boxes[0].append(button);
// let para=document.querySelector("p");
// para.remove();
let newbtn=document.createElement("button");
newbtn.innerText="click me";
newbtn.style.color="white";
newbtn.style.backgroundColor="red";
document.querySelector("body").prepend(newbtn);
let btn1=document.querySelector("#btn1");
// btn1.onclick= ()=> {
//     "console.log('clicked')"
// };
btn1.addEventListener("click",()=> {
    console.log("button was clicked");
});
// last question of l-8
let modebtn=document.querySelector("#mode");
let currmode="light";
modebtn.addEventListener("click",()=> {
    if(currmode==="light") {
        currmode="dark;"
        document.querySelector("body").style.backgroundColor="black";
    }
    else {
        currmode="light";
        document.querySelector("body").style.backgroundColor="white";
    }
    console.log(currmode);
})