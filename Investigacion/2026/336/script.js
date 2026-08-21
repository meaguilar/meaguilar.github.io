document.addEventListener("DOMContentLoaded", function () {
    const charts = [
         {
            id: "datawrapper-vis-9CvLb",
            script: "https://datawrapper.dwcdn.net/9CvLb/embed.js"
        },
        {
            id: "datawrapper-vis-KjiYr",
            script: "https://datawrapper.dwcdn.net/KjiYr/embed.js"
        },
        {
            id: "datawrapper-vis-8eIWS",
            script: "https://datawrapper.dwcdn.net/8eIWS/embed.js"
        },
        {
            id: "datawrapper-vis-CRYm7",
            script: "https://datawrapper.dwcdn.net/CRYm7/embed.js"
        },
        {
            id: "datawrapper-vis-cVLyt",
            script: "https://datawrapper.dwcdn.net/cVLyt/embed.js"
        },
        {
            id: "datawrapper-vis-Bbh30",
            script: "https://datawrapper.dwcdn.net/Bbh30/embed.js"
        }
       
       
    ];

    charts.forEach(chart => {
        const script = document.createElement("script");

        script.type = "text/javascript";
        script.defer = true;
        script.src = chart.script;
        script.charset = "utf-8";
        script.setAttribute(
            "data-target",
            "#" + chart.id
        );

        document.body.appendChild(script);
    });
});
