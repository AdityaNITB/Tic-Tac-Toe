function getData(dataId) {
    return new Promise((resolve,reject)=> {
    setTimeout(()=> {
        console.log("data",dataId);
        resolve("success");
    },3000)
});
}
async function getWeatherData() {
    await getData(1);
    await getData(2);
}
getWeatherData();