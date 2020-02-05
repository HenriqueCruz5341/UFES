const express = require('express');
const mongooose = require('mongoose');
const routes = require('./routes');
const cors = require('cors');

const app = express();

mongooose.connect('mongodb+srv://HenriqueCruz:muderecoju@cluster0-uc4sb.mongodb.net/test?retryWrites=true&w=majority', {
    useNewUrlParser: true,
    useUnifiedTopology: true,
});

app.use(cors())
app.use(express.json());
app.use(routes);

app.listen(3333);

